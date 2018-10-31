import win32gui
import time
import psutil
import win32process
import serial

ser = serial.Serial('COM37',9600)



i = 0

while i <= 1:
    time.sleep(2)
    w=win32gui
    w.GetWindowText (w.GetForegroundWindow())
    pid = win32process.GetWindowThreadProcessId(w.GetForegroundWindow())
    current = psutil.Process(pid[-1]).name()
    current = current[:-4]
    ser.write(current.encode())
    print(current)
