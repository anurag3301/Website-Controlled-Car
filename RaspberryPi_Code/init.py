from flask import Flask, render_template, request, jsonify

app = Flask(__name__)
pwm_data = [0, 0, 0, 0, 0] 

def _map(x, in_min, in_max, out_min, out_max):
    val = int((x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min)
    return val if val > 0 else 0


@app.route('/send', methods=['GET', 'POST'])
def data():
    global pwm_data 
    # POST request
    if request.method == 'POST':
        data_json=request.get_json()  # parse as JSON
        joy1X = data_json["joy1X"]
        joy1Y = data_json["joy1Y"]
        joy2X = data_json["joy2X"]
        joy2Y = data_json["joy2Y"]

        forward_pwm = _map(joy1X, 100, 150, 0, 255)
        backward_pwm = _map(joy1X, 100, 50, 0, 255)

        right_pwm =  _map(joy2Y, 100, 150, 0, 255)
        left_pwm =  _map(joy2Y, 100, 50, 0, 255)

        right_forward_pwm = max(0, forward_pwm - right_pwm)
        left_forward_pwm = max(0, forward_pwm - left_pwm)
        right_backward_pwm = max(0, backward_pwm - right_pwm)
        left_backward_pwm = max(0, backward_pwm - left_pwm)

        pwm_data = [right_forward_pwm, left_forward_pwm, right_backward_pwm, left_backward_pwm, 0]

        print(pwm_data)

        with open("/home/pi/server/pwmVal.txt", "w") as f:
            f.write(str(pwm_data[0]) + " " + str(pwm_data[1]) + " " + str(pwm_data[2]) + " " + str(pwm_data[3]) + " " +str(pwm_data[4]))
        return 'OK', 200

@app.route('/')
def hello():
    return render_template("index.html")

if __name__=="__main__":
    app.run()

