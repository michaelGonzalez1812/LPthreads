import time, threading,_thread
from tkinter import *
from tkinter import messagebox

def move_rect(rect, canvas):
    while(TRUE):
        # Valor actual banda0
        file_data = read_file("Bandas/Banda0.txt")
        if(file_data[1] != file_data_init0[1]):
            if(file_data[1] == 10):
                rect = crearRect(file_data_init0[0], canvas)
                canvas.itemconfig(rect, fill='yellow')
            else:    
                canvas.move(rect, file_data[1], 0)
                file_data_init0[1] = file_data[1]

        # valor actual banda1
        file_data = read_file("Bandas/Banda1.txt")
        if(file_data[1] != file_data_init1[1]):
            if(file_data[1] == 10):
                rect = crearRect(file_data_init1[0], canvas)
            else:    
                canvas.move(rect, file_data[1], 0)
                file_data_init1[1] = file_data[1]

        # valor actual banda2
        file_data = read_file("Bandas/Banda2.txt")
        if(file_data[1] != file_data_init2[1]):
            if(file_data[1] == 10):
                rect = crearRect(file_data_init2[0], canvas)
            else:    
                canvas.move(rect, file_data[1], 0)
                file_data_init2[1] = file_data[1]

    
    
def read_file(filename):
    #lectura del archivo
        f = open(filename, "r")
        f.readline()

        # get de los valores [tipo,posicion]
        values = (f.readline()).split(",")
        tipo = int(values[0])
        posicion = (int(values[1]))*10

        #cerrar el archivo
        f.close()
        return [tipo,posicion]


def crearRect(tipo, canvasTemp):
    if(tipo == 0):
        rectTemp = canvasTemp.create_rectangle(5, 5, 40, 25, fill="blue")
    elif(tipo == 1):
        rectTemp = canvasTemp.create_rectangle(5, 5, 40, 25, fill="red")
    else:
        rectTemp = canvasTemp.create_rectangle(5, 5, 40, 25, fill="green")
    return rectTemp

#main window
mainWindow = Tk()
mainWindow.geometry("500x300")
mainWindow.title("Envio de Paquetes")
mainWindow.config(background='white')

#canvas
canvas0 = Canvas(mainWindow, width=500, height=100)
canvas1 = Canvas(mainWindow, width=500, height=100)
canvas2 = Canvas(mainWindow, width=500, height=100)

#canvas position
canvas0.pack()
canvas1.pack()
canvas2.pack()

#canvas rect
rect0 = crearRect(0, canvas0)
rect1 = crearRect(1, canvas1)
rect2 = crearRect(2, canvas2)

#valores iniciales de posición
file_data_init0 = read_file("Bandas/Banda0.txt")
file_data_init1 = read_file("Bandas/Banda1.txt")
file_data_init2 = read_file("Bandas/Banda2.txt")

#threads
_thread.start_new_thread( move_rect,(rect0, canvas0) )
_thread.start_new_thread( move_rect,(rect1, canvas1) )
_thread.start_new_thread( move_rect,(rect2, canvas2) )


#loop window
mainWindow.mainloop()