from time import sleep

from MaestroController import Controller

c = Controller('COM4')


while True:
    c.setTarget(0, 496*4)#2496, 496
    sleep(5)
    c.setTarget(0, 2496 * 4)
    sleep(5)