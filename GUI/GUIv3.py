import time, threading,_thread
from tkinter import *
from tkinter import messagebox

#main window
mainWindow = Tk()
mainWindow.geometry("500x500")
mainWindow.title("Envio de Paquetes")

#canvas
canvas0 = Canvas(mainWindow, width=100, height=100)
canvas1 = Canvas(mainWindow, width=100, height=100)
canvas2 = Canvas(mainWindow, width=100, height=100)

#canvas position
canvas0.pack()
canvas1.pack()
canvas2.pack()

#rects
global rect0
global rect1
global rect2
rect0 = canvas0.create_rectangle(5, 5, 40, 25, fill="blue")
rect1 = canvas1.create_rectangle(5, 5, 40, 25, fill="blue")
rect2 = canvas2.create_rectangle(5, 5, 40, 25, fill="blue")

def read_file(filename, bandera, banda):
    while(TRUE):
        #lectura del archivo
        f = open(filename, bandera)
        f.readline()

        # get de los valores [tipo,posicion]
        values = (f.readline()).split(",")
        tipo = int(values[0])
        posicion = (int(values[1]))*10

        #cerrar el archivo
        f.close()

        #canvas rect
        if(tipo == 0):
            if(banda == 0):
                canvas0.move(rect0,10,0)
            elif(banda == 1):
                rect1 = canvas1.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="blue")
            else:
                rect2 = canvas2.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="blue")
        elif(tipo == 1):
            if(banda == 0):
                rect0 = canvas0.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="red")
            elif(banda == 1):
                rect1 = canvas1.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="red")
            else:
                rect2 = canvas1.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="red")
        else:
            if(banda == 0):
                rect0 = canvas0.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="green")
            elif(banda == 1):
                rect1 = canvas1.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="green")
            else:
                rect2 = canvas2.create_rectangle(5+posicion, 5, 40+posicion, 25, fill="green")

        #sleep
        time.sleep(0.1)

#thread
_thread.start_new_thread( read_file,("Bandas/Banda0.txt","r",0) )
_thread.start_new_thread( read_file,("Bandas/Banda1.txt","r",1) )
_thread.start_new_thread( read_file,("Bandas/Banda2.txt","r",2) )

#loop window
mainWindow.mainloop()