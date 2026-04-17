from flask import Flask, request
import serial

# 修改为你的Arduino串口
ser = serial.Serial('COMX', 115200, timeout=1)

app = Flask(__name__)

@app.route('/')
def home():
    return '''
    <h1>Robot Control</h1>
    <button onclick="fetch('/start')">START</button>
    <button onclick="fetch('/stop')">STOP</button>
    <button onclick="fetch('/status')">STATUS</button>
    '''

@app.route('/start')
def start():
    ser.write(b'ON\n')
    return "Robot Started"

@app.route('/stop')
def stop():
    ser.write(b'OFF\n')
    return "Robot Stopped"

@app.route('/status')
def status():
    ser.write(b'STATUS\n')
    return "Status Requested"

if __name__ == '__main__':
    app.run(host='xxx.xxx.xxx.xxx', port=4900)

    
