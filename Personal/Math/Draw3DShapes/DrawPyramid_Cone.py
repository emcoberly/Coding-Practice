import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

# Parameters for the cone
radius = 11  # radius of the cone's base
height = 7.5  # height of the cone

# Create the figure and 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Parametrization of the cone
# r is the radial distance from the z-axis (0 to radius)
# theta is the angle around the z-axis (0 to 2*pi)
r = np.linspace(0, radius, 100)  # radius values
theta = np.linspace(0, 2 * np.pi, 100)  # angle values
R, Theta = np.meshgrid(r, theta)  # create a meshgrid for r and theta

# Parametric equations for x, y, z
X = R * np.cos(Theta)  # x = r * cos(theta)
Y = R * np.sin(Theta)  # y = r * sin(theta)
Z = height - (height / radius) * R  # z = h - (h/R) * r

# Plot the cone surface with grey faces and alpha of 0.2
ax.plot_surface(X, Y, Z, color="grey", edgecolor="none", alpha=0.2)

# Plot the base circle with a linewidth of 1 (just the circle, without filling)
theta_circle = np.linspace(0, 2 * np.pi, 100)
x_circle = radius * np.cos(theta_circle)
y_circle = radius * np.sin(theta_circle)
ax.plot(x_circle, y_circle, zs=0, zdir="z", color="black", linewidth=0.5)

# Dotted line for the height of the cone
ax.plot([0, 0], [0, 0], [0, height], linestyle="--", color="black", linewidth=0.5)

# Dotted line for the radius of the cone
ax.plot([0, radius], [0, 0], [0, 0], linestyle="--", color="black", linewidth=0.5)

# Small black point at the center of the circle
ax.scatter(0, 0, 0, color="black", s=15)  # 's' controls the size of the point

# Label for the radius
ax.text(
    radius / 2,
    -1.5,
    -0.25,
    f"{radius}",
    color="black",
    fontsize=15,
    fontname="Arial",
    ha="center",
    va="center",
)

# Label for the height
ax.text(
    2,
    0,
    height / 3,
    f"{height}",
    color="black",
    fontsize=15,
    fontname="Arial",
    ha="center",
    va="center",
)

# Set axis limits to ensure uniform scaling
max_extent = max(
    radius, height / 2
)  # Find the maximum extent between radius and height
ax.set_xlim([-max_extent, max_extent])
ax.set_ylim([-max_extent, max_extent])
ax.set_zlim([0, max_extent * 2])

# Set equal aspect ratio for all axes (x, y, z)
ax.set_box_aspect([1, 1, 1])  # Ensure uniform scaling

# Remove axes, ticks, and grid
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
ax.set_axis_off()

# Show the plot
plt.show()
