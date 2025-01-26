import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():
    # Display user's portfolio
    pass

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    # Buy stocks
    pass

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    # Sell stocks
    pass

@app.route("/history")
@login_required
def history():
    # Show transaction history
    pass

@app.route("/login", methods=["GET", "POST"])
def login():
    # Log user in
    pass

@app.route("/logout")
def logout():
    # Log user out
    pass

@app.route("/register", methods=["GET", "POST"])
def register():
    # Register user
    pass

def apology(message, code=400):
    # Render apology page
    pass

def lookup(symbol):
    # Look up stock price
    pass

def usd(value):
    # Format value as USD
    pass