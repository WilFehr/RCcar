# RCcar
What Does Success Look Like?

A remote controlled car

# Focus:
The focus of this project is on project management, as I will be using Notion to track tasks, priorities, 
and dependencies, and the engineering design cycle, as I will be planning, researching, designing, consulting with peers and mentors, 
and iterating as necessary to complete this project.

This will be a multidisciplinary project, 
However as I am an electrical engineering student that will be the focus of my work, 
and I may opt for a more practical solution when it comes to design implementation and choose premade components or reference existing libraries, 
as the physical construction and the software are not the priorities of this project.

# What Will be Documented Here:
In this repo, I will be:
- documenting sources and tracking research;
- version control for the solidworks files, KiCad files, and relavent code files;
- posting finalized documents such as weighted objectives charts, and decisions evaluation matrices;
- and crediting my collaborators

# List of Collaborators:
## Andrew
- helped define project scope


# Goals:
- Wireless control
- Controlled using external hard ware
- Drives straight when directed to do so
- Can turn in motion
- Mostly 3d printed
- Battery powered


# Wants:
- Main microcontroller to be the ATMega328P,(can use arduino for testing)
- Be able to live read data such as speed, distance travelled, orientation(has it flipped over), [more?]



# To Research:
these are the topics that I will need to look into before making any design decisions
## Wireless Communication Methods:
### Things to Keep in Mind while Researching:
- Cost(additional components)
- Ease of implementation
- Restrictions due to legality(RF stuff)
- Restrictions of physical implementation(i.e. things that block the signal/impede communication/required proximity to/from components)
### Things to Consider for Design Selection:
- Visibility of IR

## Motors:
### Things to Keep in Mind while Researching:
- Cost
- Built in encoders?
- Size
- Power output(will need weight estimate for minimum required power)

## Servos(if needed):
### Things to Keep in Mind while Researching:
- Cost
- Built in encoders?
- Size
- Power output(may need weight estimate for minimum required power)

## Encoders:
- Cost
- Mounting
- Communication with Controller

## Tracking Speed and Acceleration:
- get an additional sensor
- calculate value using distance track via encoders

## Additional Sensors:
- something to track orientation


## PID:
- Gotta figure out how to implement this for the motors

## Internal communication methods for sensors:
- I2C
- CANBUS
- SPI

## Turning mechanisms:
- Turn one side faster
- One forward and one backwards
- turning how cars do with H shaped thing

## Wheel and tire material:
- existing parts
- 3D printing

## Suspension of wheel systems:
- talk to friends in mech for ideas

## Form and operation factor of controller:
### Acceleration:
- Trigger
- Dial
- Lever
### Steering:
- Dial
- Horizontal lever
- Tilt

## Body:
- Will likely have to be custom made
	- simple shape
 	- 3D printable

# Expanding the scope:
## Battery Charger for the Main Car Battery: 
- must be compatible with wall NA outlets
- will require additional research into batteries
- Battery chargers/wall outlet safety(initial research prompts):
	- Things to keep in mind:
	- WALL OUTLETS ARE DANGEROUS(TALK TO ELECTRICIAN/MORE EXPERIENCED PERSON BEFORE DOING ANYTHING)
	- Some rectifier
	- How to lower the voltage
## Use Microcontroller STM32:
- I have an STM32 F303RE, so can use that for prototyping.
## Do Pre-Programmed Missions:
- Store mission on sd card, will need to look into how do this
## Low Power Mode to Turn On and Off the Car Using the Remote
