# RCcar
What does success look like?

A remote controlled car

# Goals:
Wireless control
Controlled using external hard ware
Can pre program and load trips(ie. Move forward 2m, turn right 90 degrees, and  forward 1m)(not done wirelessly)(start using onboard button)
Drives straight when directed to do so
Can turn in motion
Mostly 3d printed
Battery powered


# Wants:
Main microcontroller the - from Andrew(can use arduino to test) initially after finalized vehicle body and sensors, 

Make a battery recharger that is compatible with wall outlets

Be able to live read data such as speed, distance travelled, orientation(has it flipped over), [more?]


# To research:
(initial research starting points)
Wireless communication methods:
	Things to keep in mind:
Cost(additional components) 
Ease of implementation
Restrictions due to legality
Restrictions of physical implementation(i.e. things that block the signal/impede communication/required proximity to/from components)
Things to consider:
Visibility of IR
 
Battery chargers/wall outlet safety:
Things to keep in mind:
WALL OUTLETS ARE DANGEROUS(TALK TO UNCLE CHRIS BEFORE DOING ANYTHING)
Some rectifier
How to lower the voltage

Motors:
	Things to keep in mind:
Cost
Built in encoders?
Size
Power output(will need weight estimate for minimum required power)

Servos(if needed):
	Things to keep in mind:
Cost
Built in encoders?
Size
Power output(will need weight estimate for minimum required power)

PID:
Gotta figure out how to implement this for the motors

Internal communication methods for sensors:
I2C?
CANBUS?

Turning mechanisms:
Turn one side faster
One forward and one backwards
turning

Wheel and tire material:


Suspension of wheel systems:


Form factor of controller:


# Expanding the scope:
Use microcontroller stm32 303FE
Store mission on sd card, will need to look into how 
A low power mode to allow for remote turn on of the remote
