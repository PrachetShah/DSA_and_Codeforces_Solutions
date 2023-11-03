# Create a basic Flask web app
from flask import Flask

app = Flask(__name__)

@app.route("/")
def method():
    return "Hello World from Flask Server"

app.run()
