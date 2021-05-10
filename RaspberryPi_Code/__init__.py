from flask import Flask, render_template, request, jsonify
app = Flask(__name__)

@app.route('/hello', methods=['GET', 'POST'])
def data():

    # POST request
    if request.method == 'POST':
        print('Incoming..')
        data_json=request.get_json()  # parse as JSON
        joy1X = data_json["joy1X"], data_json["joy1Y"], data_json["joy2X"], data_json["joy2Y"])
        joy1Y = data_json["joy1Y"]
        joy2X = data_json["joy2X"]
        joy2Y = data_json["joy2Y"]
        return 'OK', 200

    # GET request
    else:
        message = {'greeting':'Hello from Flask!'}
        print(jsonify(message))

@app.route('/')
def hello():
    return render_template("index.html")

if __name__=="__main__":
    app.run()
