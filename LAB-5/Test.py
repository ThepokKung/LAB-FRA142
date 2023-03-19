import math
import pygame

# Initialize Pygame
pygame.init()

# Set up the game window
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))

# Set up the projectile
x = screen_width/2
y = screen_height/2
u = 50 # initial velocity magnitude
theta = math.pi/4 # launch angle in radians
vx = u*math.cos(theta) # horizontal velocity component
vy = -u*math.sin(theta) # vertical velocity component (negative because y-axis is flipped in Pygame)
a = 9.81 # acceleration due to gravity (m/s^2)
t = 0 # elapsed time
dt = 0.01 # time step
radius = 10

# Game loop
while True:
    # Handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()

    # Update the projectile's position and velocity
    t += dt
    x += vx*dt
    y += vy*dt + 0.5*a*dt**2
    vy += a*dt

    # Clear the screen
    screen.fill((255, 255, 255))

    # Draw the projectile
    pygame.draw.circle(screen, (255, 0, 0), (int(x), int(y)), radius)

    # Update the display
    pygame.display.update()