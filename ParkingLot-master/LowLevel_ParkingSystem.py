import Vehicle
import argparse
import sys
 
if sys.version_info[0] == 2:
	input = raw_input

class ParkingLot:
	def __init__(self):
		self.capacity = 0
		self.slotid = 0
		self.numOfOccupiedSlots = 0

	def createParkingLot(self,capacity):
		self.slots = [-1] * capacity
		self.capacity = capacity
		return self.capacity

	def getEmptySlot(self):
		for i in range(len(self.slots)):
			if self.slots[i] == -1:
				return i

	def park(self,regno,color):
		if self.numOfOccupiedSlots < self.capacity: 
			slotid = self.getEmptySlot()
			self.slots[slotid] = Vehicle.Car(regno,color)
			self.slotid = self.slotid+1
			self.numOfOccupiedSlots = self.numOfOccupiedSlots + 1
			return slotid+1
		else:
			return -1

	def leave(self,slotid):

		if self.numOfOccupiedSlots > 0 and self.slots[slotid-1] != -1:
			self.slots[slotid-1] = -1
			self.numOfOccupiedSlots = self.numOfOccupiedSlots - 1
			return True
		else:
			return False

	def status(self):
		print("Slot No.\tRegistration No.\tColour")
		for i in range(len(self.slots)):
			if self.slots[i] != -1:
				print(str(i+1) + "\t\t" +str(self.slots[i].regno) + "\t\t" + str(self.slots[i].color))
			else:
				continue

	def getRegNoFromColor(self,color):

		regnos = []
		for i in self.slots:

			if i == -1:
				continue
			if i.color == color:
				regnos.append(i.regno)
		return regnos
			
	def getSlotNoFromRegNo(self,regno):
		
		for i in range(len(self.slots)):
			if self.slots[i].regno == regno:
				return i+1
			else:
				continue
		return -1
			

	def getSlotNoFromColor(self,color):
		
		slotnos = []

		for i in range(len(self.slots)):

			if self.slots[i] == -1:
				continue
			if self.slots[i].color == color:
				slotnos.append(str(i+1))
		return slotnos

	def show(self,line):
		if line.startswith('create_parking_lot'):
			n = int(line.split(' ')[1])
			res = self.createParkingLot(n)
			print('Created a parking lot with '+str(res)+' slots')

		elif line.startswith('park'):
			regno = line.split(' ')[1]
			color = line.split(' ')[2]
			res = self.park(regno,color)
			if res == -1:
				print("Sorry, parking lot is full")
			else:
				print('Allocated slot number: '+str(res))

		elif line.startswith('leave'):
			leave_slotid = int(line.split(' ')[1])
			status = self.leave(leave_slotid)
			if status:
				print('Slot number '+str(leave_slotid)+' is free')

		elif line.startswith('status'):
			self.status()

		elif line.startswith('check_car_number_with_carcolor'):
			color = line.split(' ')[1]
			regnos = self.getRegNoFromColor(color)
			print(', '.join(regnos))

		elif line.startswith('check_slot_number_with_carcolor'):
			color = line.split(' ')[1]
			slotnos = self.getSlotNoFromColor(color)
			print(', '.join(slotnos))

		elif line.startswith('check_slot_number_with_carno'):
			regno = line.split(' ')[1]
			slotno = self.getSlotNoFromRegNo(regno)
			if slotno == -1:
				print("Not found")
			else:
				print(slotno)
		elif line.startswith('exit'):
			exit(0)

def main():

	parkinglot = ParkingLot()
	parser = argparse.ArgumentParser()
	parser.add_argument('-f', action="store", required=False, dest='src_file', help="Input File")
	args = parser.parse_args()
	
	if args.src_file:
		with open(args.src_file) as f:
			for line in f:
				line = line.rstrip('\n')
				parkinglot.show(line)
	else:
			while True:
				line = input("$ ")
				parkinglot.show(line)

if __name__ == '__main__':
	print("----------Welcome to Low Level Parking Lot System-----------------")
	print("Type following commands to perform operations on Parking system")
	print("1. create_parking_lot n (n=capacity)")
	print("2. park car_number var_color")
	print("3. status")
	print("4. leave x (x=slot number)")
	print("5. check_car_number_with_carcolor car_color")
	print("6. check_slot_number_with_carcolor car_color")
	print("7. check_slot_number_with_carno car_no")
	print("Exit")
	print("-------------------------------------------------------------------")
	main() 