import time, threading,_thread
from tkinter import *
from tkinter import messagebox

#main window
mainWindow = Tk()
mainWindow.geometry("500x500")
mainWindow.title("Envio de Paquetes")

#buttons
global btn0
global btn1
global btn2
btn0 = Button(mainWindow, bg="blue", width=10, height=2, command=quit).place(x=5, y=5)
btn1 = Button(mainWindow, bg="red", width=10, height=2, command=quit).place(x=5, y=55)
btn2 = Button(mainWindow, bg="green", width=10, height=2, command=quit).place(x=5, y=105)


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
                (Button(btn0)).config(bg = "blue")
                (Button(btn0)).place(x=posicion, y=5)
            elif(banda == 1):
                (Button(btn1)).config(bg = "blue")
                (Button(btn1)).place(x=posicion, y=55)
            else:
                (Button(btn2)).config(bg = "blue")
                (Button(btn2)).place(x=posicion, y=105)
        elif(tipo == 1):
            if(banda == 0):
                (Button(btn0)).config(bg = "red")
                (Button(btn0)).place(x=posicion, y=5)
            elif(banda == 1):
                (Button(btn1)).config(bg = "red")
                (Button(btn1)).place(x=posicion, y=55)
            else:
                (Button(btn2)).config(bg = "red")
                (Button(btn2)).place(x=posicion, y=105)
        else:
            if(banda == 0):
                (Button(btn0)).config(bg = "green")
                (Button(btn0)).place(x=posicion, y=5)
            elif(banda == 1):
                (Button(btn1)).config(bg = "green")
                (Button(btn1)).place(x=posicion, y=55)
            else:
                (Button(btn2)).config(bg = "green")
                (Button(btn2)).place(x=posicion, y=105)

        #sleep
        time.sleep(0.1)

#thread
_thread.start_new_thread( read_file,("Bandas/Banda0.txt","r",0) )
_thread.start_new_thread( read_file,("Bandas/Banda1.txt","r",1) )
_thread.start_new_thread( read_file,("Bandas/Banda2.txt","r",2) )

#loop window
mainWindow.mainloop()