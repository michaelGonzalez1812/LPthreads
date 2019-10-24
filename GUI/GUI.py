'''/*************************************************************
 * Tecnológico de Costa Rica
 * Conceptos básicos de Sistemas Operativos
 * Athors:
 *      Michael Gonzalez Rivera
 *      Erick Cordero Rojas
 *      Victor Montero
 * 
 * Description:
 *      GUI aplication
 * ***********************************************************/'''
 
import time, threading,_thread
from tkinter import *
from tkinter import messagebox


def movement(canvas): 

    rect00 = rect0
    rect11 = rect1
    rect22 = rect2

    # Valor actual banda0
    file_data = read_file("Bandas/Banda0.txt")
    if(file_data[1] != file_data_init0[1]):
        if(file_data[0] == 0):
            canvas0.itemconfig(rect00, fill='blue')
            canvas0.coords(rect00,file_data[1], 5, file_data[1]+40, 25)
        elif(file_data[0] == 1):
            canvas0.itemconfig(rect00, fill='red')
            canvas0.coords(rect00,file_data[1], 5, file_data[1]+40, 25)
        else:
            canvas0.itemconfig(rect00, fill='green')
            canvas0.coords(rect00,file_data[1], 5, file_data[1]+40, 25)   
        file_data_init0[1] = file_data[1]

    # valor actual banda1
    file_data = read_file("Bandas/Banda1.txt")
    if(file_data[1] != file_data_init1[1]):
        if(file_data[0] == 0):
            canvas1.itemconfig(rect11, fill='blue')
            canvas1.coords(rect00,file_data[1], 5, file_data[1]+40, 25)
        elif(file_data[0] == 1):
            canvas1.itemconfig(rect11, fill='red')
            canvas1.coords(rect00,file_data[1], 5, file_data[1]+40, 25)
        else:
            canvas1.itemconfig(rect11, fill='green')
            canvas1.coords(rect00,file_data[1], 5, file_data[1]+40, 25)   
        file_data_init0[1] = file_data[1]

    # valor actual banda2
    file_data = read_file("Bandas/Banda2.txt")
    if(file_data[1] != file_data_init2[1]):
        if(file_data[0] == 0):
            canvas2.itemconfig(rect22, fill='blue')
            canvas2.coords(rect22,file_data[1], 5, file_data[1]+40, 25)
        elif(file_data[0] == 1):
            canvas2.itemconfig(rect22, fill='red')
            canvas2.coords(rect22,file_data[1], 5, file_data[1]+40, 25)
        else:
            canvas2.itemconfig(rect22, fill='green')
            canvas2.coords(rect22,file_data[1], 5, file_data[1]+40, 25)   
        file_data_init0[1] = file_data[1]
        
    # llamda recursiva
    canvas.after(10, movement, canvas) 
    
def read_file(filename):
    #lectura del archivo
    tipo = 0
    posicion = 1
    try:
        f = open(filename, "r")

        # get de los valores [tipo,posicion]
        values = (f.readline()).split(",")
        tipo = int(values[0])
        posicion = (int(values[1]))*50
    except:
        print("Miss read")
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

# load the .gif image file
#gif1 = PhotoImage(file="../Bandas/Banda.jpg")

# put gif image on canvas
#canvas0.create_image(50, 10, image=gif1, anchor=NW)
#canvas1.create_image(50, 10, image=gif1, anchor=NW)
#canvas2.create_image(50, 10, image=gif1, anchor=NW)


#valores iniciales de posición
file_data_init0 = read_file("Bandas/Banda0.txt")
file_data_init1 = read_file("Bandas/Banda1.txt")
file_data_init2 = read_file("Bandas/Banda2.txt")

#canvas rect
rect0 = crearRect(file_data_init0[0], canvas0)
rect1 = crearRect(file_data_init1[0], canvas1)
rect2 = crearRect(file_data_init2[0], canvas2)

#canvas move
mainWindow.after(300, movement,canvas0)

#loop window
mainWindow.mainloop()