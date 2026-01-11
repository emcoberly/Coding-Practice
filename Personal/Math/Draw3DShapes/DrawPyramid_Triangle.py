import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection

# Base triangle dimensions
triangle_base = 5
triangle_height = 12
pyramid_height = 13

# Triangle vertices in x-y plane (isosceles, centered at origin)
v0 = (-triangle_base / 2, 0, 0)  # Left base point
v1 = (triangle_base / 2, 0, 0)  # Right base point
v2 = (0, triangle_height, 0)  # Top vertex (isosceles peak)

# Pyramid apex (above the centroid of the triangle)
# Centroid of triangle (average of x and y)
centroid_x = (v0[0] + v1[0] + v2[0]) / 3
centroid_y = (v0[1] + v1[1] + v2[1]) / 3
apex = (centroid_x, centroid_y, pyramid_height)

# Collect all vertices
vertices = [v0, v1, v2, apex]

# Faces (3 sides, no base)
faces = [[v0, v1, apex], [v1, v2, apex], [v2, v0, apex]]

# Create figure
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Draw pyramid
pyramid = Poly3DCollection(
    faces, facecolors="grey", edgecolors="black", linewidths=0.4, alpha=0.2
)
ax.add_collection3d(pyramid)

# Draw height of triangle (from base midpoint to triangle tip)
base_midpoint = ((v0[0] + v1[0]) / 2, (v0[1] + v1[1]) / 2, 0)
triangle_apex = v2
ax.plot(
    [base_midpoint[0], triangle_apex[0]],
    [base_midpoint[1], triangle_apex[1]],
    [0, 0],
    linestyle="--",
    color="black",
    linewidth=0.4,
)

# Draw height of pyramid (from triangle centroid to apex)
ax.plot(
    [centroid_x, apex[0]],
    [centroid_y, apex[1]],
    [0, apex[2]],
    linestyle="--",
    color="black",
    linewidth=0.4,
)

# Previous right-angle marker between the height of the triangle base and the height of the pyramid
marker_size = 0.75  # Size of the square for the right angle marker

# Coordinates of the right angle marker in the y-z plane at the intersection of the two dotted lines
right_angle_marker = [
    # First segment (along the z-axis, from the base)
    [centroid_x, centroid_y, 0],
    [centroid_x, centroid_y, marker_size],  # Move up the z-axis
    # Second segment (along the y-axis)
    [centroid_x, centroid_y, marker_size],  # Continue from the previous point
    [centroid_x, centroid_y + marker_size, marker_size],  # Move along the y-axis
    # Third segment (flush with the z-axis)
    [centroid_x, centroid_y + marker_size, marker_size],  # Back to the starting point
    [centroid_x, centroid_y + marker_size, 0],  # Close the marker
]

# Add the previous right-angle marker to the plot
right_angle_lines = Line3DCollection(
    [right_angle_marker], colors="black", linewidths=0.4
)
ax.add_collection3d(right_angle_lines)

# New right-angle marker in the x-y plane at the intersection of the base and height
right_angle_marker_xy = [
    # First segment (along the y-axis, from the base midpoint)
    [base_midpoint[0], base_midpoint[1], 0],
    [base_midpoint[0], base_midpoint[1] + marker_size, 0],  # Move along the y-axis
    # Second segment (along the x-axis)
    [
        base_midpoint[0],
        base_midpoint[1] + marker_size,
        0,
    ],  # Continue from the previous point
    [
        base_midpoint[0] + marker_size,
        base_midpoint[1] + marker_size,
        0,
    ],  # Move along the x-axis
    # Third segment (flush with the y-axis)
    [
        base_midpoint[0] + marker_size,
        base_midpoint[1] + marker_size,
        0,
    ],  # Back to the starting point
    [base_midpoint[0] + marker_size, base_midpoint[1], 0],  # Close the marker
]

# Add the new right-angle marker to the plot
right_angle_lines_xy = Line3DCollection(
    [right_angle_marker_xy], colors="black", linewidths=0.4
)
ax.add_collection3d(right_angle_lines_xy)

# Font settings
label_font = {"fontname": "Arial", "fontsize": 15}

# Label triangle height
label_x = (base_midpoint[0] + triangle_apex[0]) / 2 + 0.5
label_y = (base_midpoint[1] + triangle_apex[1]) / 3
ax.text(
    label_x,
    label_y,
    -0.2,
    f"{triangle_height}",
    color="black",
    ha="left",
    va="center",
    **label_font,
)

# Label pyramid height
label_x = (centroid_x + apex[0]) / 2 + 0.3
label_y = (centroid_y + apex[1]) / 2
label_z = apex[2] / 3
ax.text(
    label_x,
    label_y,
    label_z,
    f"{pyramid_height}",
    color="black",
    ha="left",
    va="center",
    **label_font,
)

# Label base of the triangle
label_x = (v0[0] + v1[0]) / 2
label_y = -0.5  # Just below the base
ax.text(
    label_x,
    label_y,
    0,
    f"{triangle_base}",
    color="black",
    ha="center",
    va="top",
    **label_font,
)

# Uniform axis limits
max_extent = max(triangle_base, triangle_height, pyramid_height)
ax.set_xlim(-max_extent / 2, max_extent / 2)
ax.set_ylim(-1, triangle_height + 5)
ax.set_zlim(0, pyramid_height + 3)

# Set equal aspect ratio for all axes (x, y, z)
ax.set_box_aspect([1, 1, 1])  # This will ensure uniform scaling

# Remove axes, ticks, and grid
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
ax.set_axis_off()

plt.show()
