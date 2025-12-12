import serial

ser = serial.Serial('/dev/ttyACM1', 115200, timeout=1)

print("🔌 Arduino'dan gelen mesajlar:")
try:
    while True:
        line = ser.readline().decode().strip()
        if line:
            print("📟", line)
except KeyboardInterrupt:
    print("🛑 Test durduruldu.")
finally:
    ser.close()