import serial 
import argparse
import string
import time 
import base64
import datetime
def send_start_command_to_arduino(serial_port): 
	time_out = 1
	time.sleep(time_out)
	serial_port.setDTR(0)
	time.sleep(time_out)
	serial_port.write(b'5')
	serial_port.flushInput()
	time.sleep(time_out)

def write_to_file(file, data, open, time):
	if(data != 0 and file == ''): 
		print('H')
		data = data - 1
		return str(open + time + ".csv")
	
if __name__ == "__main__":
	# baud_rate = 115200
	# file_name = ['', '', '']
	# created = [False, False, False]
	# parser = argparse.ArgumentParser(); 
	# parser.add_argument(dest = 'port', help = "display the interface port to the computer ", type = str)
	# args = parser.parse_args() 
	# port = args.port 
	# serial_port = serial.Serial(port, baud_rate, timeout = 1)
	# send_start_command_to_arduino(serial_port)
	# while 1: 
		# try: 	
			# data = (serial_port.read(size = 18))
			# timestr = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
			# file_name[0] = write_to_file(file_name[0], data[9], "fib_sci", timestr)
			# file_name[1] = write_to_file(file_name[1], data[10], "fob_sci", timestr)
			# file_name[2] = write_to_file(file_name[2], data[11], "fsc_sci", timestr)
			# print (file_name[1]);
			# with open((file_name[1]), "a") as f: 
					# f.write("fsc_sci_" + timestr)
		# except serial.SerialTimeoutException:
			# print("DATA COULD NOT BE READ")  
	
	parser = argparse.ArgumentParser();
	parser.add_argument(dest = 'port', help = "display the interface port to the computer ", type = str)
	args = parser.parse_args() 
	
	s = serial.Serial(args.port, 115200, timeout = 1)
	
	# arduino startup time
	time.sleep(1)
	
	t = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
	s.write(b'5')
	with open("fib_sci_" + t + ".csv", 'w') as f, open ("fob_sci_" + t + ".csv", 'w') as se, open ("fsc_sci_" + t + ".csv", 'w') as d:
		while True:
			try:
				#a = 2
				data = s.read(size = 18)
				#print(data)
				f.write(datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f") + "," + "{}".format(int.from_bytes(data[1:5], 'big')) + "\n")
				d.write(datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f") + "," + "{}".format(int.from_bytes(data[1:5], 'big')) + "\n")
				se.write(datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S.%f") + "," + "()".format(int.from_bytes(data[1:5], 'big')) + "\n")
			except KeyboardInterrupt:
				break;

			
			
	
	
		
	
	