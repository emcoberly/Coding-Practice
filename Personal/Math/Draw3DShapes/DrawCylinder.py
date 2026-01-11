import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

# Parameters for the cylinder
radius = 10  # radius of the cylinder's base
height = 20  # height of the cylinder

# Create the figure and 3D axis
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Parametrization of the cylinder
# r is the radial distance from the z-axis (constant, i.e., the radius)
# theta is the angle around the z-axis (0 to 2*pi)
theta = np.linspace(0, 2 * np.pi, 100)  # angle values
z = np.linspace(0, height, 100)  # z values range from 0 to height
theta, Z = np.meshgrid(theta, z)  # create a meshgrid for theta and z

# Parametric equations for x, y (cylinder equations)
X = radius * np.cos(theta)  # x = r * cos(theta)
Y = radius * np.sin(theta)  # y = r * sin(theta)

# Plot the cylinder surface with grey faces and alpha of 0.2
ax.plot_surface(X, Y, Z, color="grey", edgecolor="none", alpha=0.2)

# Plot the base circle at z=0 with a linewidth of 0.5 (just the circle, without filling)
theta_circle = np.linspace(0, 2 * np.pi, 100)
x_circle = radius * np.cos(theta_circle)
y_circle = radius * np.sin(theta_circle)
ax.plot(x_circle, y_circle, zs=0, zdir="z", color="black", linewidth=0.25)

# Plot the top circle at z=height with a linewidth of 0.5 (just the circle, without filling)
ax.plot(x_circle, y_circle, zs=height, zdir="z", color="black", linewidth=0.25)

# Dotted line for the height of the cylinder
ax.plot([0, 0], [0, 0], [0, height], linestyle="--", color="black", linewidth=0.5)

# Dotted line for the radius of the cylinder
ax.plot([0, radius], [0, 0], [0, 0], linestyle="--", color="black", linewidth=0.5)

# Small black point at the center of the base circle
ax.scatter(0, 0, 0, color="black", s=10)  # 's' controls the size of the point

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
    1.5,
    0,
    height / 2,
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
