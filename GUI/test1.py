import time, threading,_thread
from tkinter import *
from tkinter import messagebox
import queue


def movement(value, canvas, rect, tipo): 

    # This is where the move() method is called 
    # This moves the rectangle to x, y coordinates 
    canvas.move(rect, value, 0) 
    cordenadas = canvas.coords(rect)

    if(cordenadas[0] >= 150.0):
        if(tipo == 0):
            rect = canvas.create_rectangle(5, 5, 75, 25, fill="blue")
        elif(tipo == 1):
            rect = canvas.create_rectangle(5, 5, 75, 25, fill="red")
        else:
            rect = canvas.create_rectangle(5, 5, 75, 25, fill="green")
    canvas.after(100, movement, value, canvas, rect, tipo) 
    
def read_file():
    f = open("interfaz.txt", "r")
    nt = len(f.readlines())
    line_cont_total = 0
    for x in f:
        line_cont_total+=1
        packagesQ.put(line.split(","))
    f.close()
    while(TRUE):
        f = open("interfaz.txt", "r")
        n = len(f.readlines())
        line_cont = 0
        for x in f:
            line_cont+=1
            if(line_cont >= nt):
                packagesQ.put(line.split(","))
        f.close()
        print(packagesQ.qsize())


        time.sleep(0.1)
#main window
mainWindow = Tk()
mainWindow.geometry("500x500")
mainWindow.title("Envio de Paquetes")

#pacakges queue
packagesQ = queue.Queue()

#thread
_thread.start_new_thread( read_file,() )

#canvas
canvas1 = Canvas(mainWindow, width=500, height=100)
canvas2 = Canvas(mainWindow, width=500, height=100)
canvas3 = Canvas(mainWindow, width=500, height=100)

#canvas position
canvas1.pack()
canvas2.pack()
canvas3.pack()

#canvas rect
rect1 = canvas1.create_rectangle(5, 5, 75, 25, fill="blue")
rect2 = canvas2.create_rectangle(5, 5, 75, 25, fill="red")
rect3 = canvas3.create_rectangle(5, 5, 75, 25, fill="green")

#canvas move
mainWindow.after(300, movement,1,canvas1,rect1,0)
mainWindow.after(300, movement,3,canvas2,rect2,1)
mainWindow.after(300, movement,2,canvas3,rect3,2)

#loop window
mainWindow.mainloop()