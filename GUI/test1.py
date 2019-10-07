import time, threading
from tkinter import *
from tkinter import messagebox


def movement(value, canvas, rect, tipo): 

    # This is where the move() method is called 
    # This moves the rectangle to x, y coordinates 
    canvas.move(rect, value, 0) 
    cordenadas = canvas.coords(rect)

    if(cordenadas[0] >= 75.0):
        if(tipo == 0):
            rect = canvas.create_rectangle(5, 5, 25, 25, fill="blue")
        elif(tipo == 1):
            rect = canvas.create_rectangle(5, 5, 25, 25, fill="red")
        else:
            rect = canvas.create_rectangle(5, 5, 25, 25, fill="green")
    canvas.after(100, movement, value, canvas, rect, tipo) 
    

mainWindow = Tk()
mainWindow.geometry("500x500")
mainWindow.title("Envio de Paquetes")
canvas1 = Canvas(mainWindow, width=500, height=100)
canvas1.pack()
rect1 = canvas1.create_rectangle(5, 5, 25, 25, fill="blue")
canvas2 = Canvas(mainWindow, width=500, height=100)
canvas2.pack()
rect2 = canvas2.create_rectangle(5, 5, 25, 25, fill="red")
canvas3 = Canvas(mainWindow, width=500, height=100)
canvas3.pack()
rect3 = canvas3.create_rectangle(5, 5, 25, 25, fill="green")
mainWindow.after(300, movement,1,canvas1,rect1,0)
mainWindow.after(300, movement,3,canvas2,rect2,1)
mainWindow.after(300, movement,2,canvas3,rect3,2)
mainWindow.mainloop()