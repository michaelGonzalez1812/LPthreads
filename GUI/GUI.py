# imports every file form tkinter and tkinter.ttk 
from tkinter import *
from tkinter.ttk import *
import _thread

class GFG: 
	def __init__(self, master = None): 
		self.master = master 
		
		# to take care movement in x direction 
		self.x = 1
		# to take care movement in y direction 
		self.y = 0

		# Set up the thread to do asynchronous I/O
        # More threads can also be created and used, if necessary
		#_thread.start_new_thread( movement, () )

		# canvas object to create shape 
		self.canvas = Canvas(master) 
		self.canvas2 = Canvas(master) 
		self.canvas3 = Canvas(master) 
		# creating rectangle 
		self.rectangle = self.canvas.create_rectangle( 
						5, 5, 25, 25, fill = "black") 
		self.rectangle2 = self.canvas2.create_rectangle( 
						5, 5, 25, 25, fill = "blue") 
		self.rectangle3 = self.canvas3.create_rectangle( 
						5, 5, 25, 25, fill = "red") 
		self.canvas.pack() 
		self.canvas2.pack() 
		self.canvas3.pack() 

		# calling class's movement method to 
		# move the rectangle 
		self.movement() 
	
	def movement(self): 

		# This is where the move() method is called 
		# This moves the rectangle to x, y coordinates 
		self.canvas.move(self.rectangle, self.x, self.y) 
		self.canvas2.move(self.rectangle2, self.x, self.y) 
		self.canvas3.move(self.rectangle3, self.x, self.y) 

		self.canvas.after(100, self.movement) 
	

if __name__ == "__main__": 

	# object of class Tk, resposible for creating 
	# a tkinter toplevel window 
	master = Tk() 
	gfg = GFG(master) 

	# Infnite loop breaks only by interrupt 
	mainloop() 

