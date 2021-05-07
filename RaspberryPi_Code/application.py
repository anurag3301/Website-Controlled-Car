from flask import Flask, render_template, request
from flask.wrappers import Request

app = Flask(__name__)

@app.route("/")

def index():
    return render_template("index.html", name=request.args.get("name"))
