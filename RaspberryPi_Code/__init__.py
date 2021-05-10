from flask import Flask, render_template, request, jsonify
app = Flask(__name__)

@app.route('/hello', methods=['GET', 'POST'])
def data():

    # POST request
    if request.method == 'POST':
        print('Incoming..')
        print(request.get_json())  # parse as JSON
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
