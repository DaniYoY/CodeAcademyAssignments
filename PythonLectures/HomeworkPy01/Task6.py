import pygame
import sys

# Game settings
SCREEN_WIDTH, SCREEN_HEIGHT = 800, 800
PACMAN_SIZE = 50
DOT_SIZE = 20
DOT_COLOR = (255, 255, 255)  # White
PACMAN_COLOR = (255, 255, 0)  # Yellow
BG_COLOR = (0, 0, 0)  # Black

# Initialize the game
pygame.init()
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
clock = pygame.time.Clock()

# Player
pacman = pygame.Rect(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2, PACMAN_SIZE, PACMAN_SIZE)

# Dots
dots = [pygame.Rect(x, y, DOT_SIZE, DOT_SIZE) for x in range(50, SCREEN_WIDTH, 100) for y in range(50, SCREEN_HEIGHT, 100)]

# Game loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Player movement
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        pacman.move_ip(-5, 0)
    if keys[pygame.K_RIGHT]:
        pacman.move_ip(5, 0)
    if keys[pygame.K_UP]:
        pacman.move_ip(0, -5)
    if keys[pygame.K_DOWN]:
        pacman.move_ip(0, 5)
    pacman.clamp_ip(screen.get_rect())  # Keep the player inside the screen

    # Eat dots
    for dot in dots[:]:
        if pacman.colliderect(dot):
            dots.remove(dot)

    # Drawing
    screen.fill(BG_COLOR)
    for dot in dots:
        pygame.draw.ellipse(screen, DOT_COLOR, dot)
    pygame.draw.ellipse(screen, PACMAN_COLOR, pacman)

    # Refresh the display
    pygame.display.flip()

    # Cap at 60 FPS
    clock.tick(60)