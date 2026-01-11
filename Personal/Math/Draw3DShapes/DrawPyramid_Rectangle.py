import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection, Line3DCollection

# Dimensions
length = 30  # along x-axis
width = 25  # along y-axis
height = 25  # along z-axis

# Vertices
base_center = (0, 0, 0)
apex = (0, 0, height)

# Base vertices (clockwise)
vertices = [
    (-length / 2, -width / 2, 0),  # 0
    (length / 2, -width / 2, 0),  # 1
    (length / 2, width / 2, 0),  # 2
    (-length / 2, width / 2, 0),  # 3
    apex,  # 4
]

# Faces of the pyramid (no base face)
faces = [
    [vertices[0], vertices[1], apex],
    [vertices[1], vertices[2], apex],
    [vertices[2], vertices[3], apex],
    [vertices[3], vertices[0], apex],
]

# Create figure
fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# Draw pyramid (no bottom face)
pyramid = Poly3DCollection(
    faces, facecolors="grey", edgecolors="black", linewidths=0.4, alpha=0.2
)
ax.add_collection3d(pyramid)

# Draw dotted height line from base center to apex
ax.plot([0, 0], [0, 0], [0, height], linestyle="--", color="black", linewidth=0.4)

# Draw right-angle marker in x-z plane
marker_size = 3
right_angle_marker = [
    [(0, 0, 0), (marker_size, 0, 0)],
    [(marker_size, 0, 0), (marker_size, 0, marker_size)],
    [(marker_size, 0, marker_size), (0, 0, marker_size)],
]
right_angle_lines = Line3DCollection(right_angle_marker, colors="black", linewidths=0.4)
ax.add_collection3d(right_angle_lines)

# Font settings
label_font = {"fontname": "Arial", "fontsize": 15}

# Height label (offset slightly up z-axis)
ax.text(
    0.3, 0, height / 3, f"{height}", color="black", ha="left", va="center", **label_font
)

# Length label (x-axis, offset downward in y-axis)
mid_x = (vertices[0][0] + vertices[1][0]) / 2
ax.text(
    mid_x,
    vertices[0][1] - 1.2,
    -0.5,
    f"{length}",
    color="black",
    ha="center",
    va="top",
    **label_font,
)

# Width label (y-axis, offset in x-direction)
mid_y = (vertices[1][1] + vertices[2][1]) / 2
ax.text(
    vertices[1][0] + 1.0,
    mid_y,
    -0.5,
    f"{width}",
    color="black",
    ha="left",
    va="center",
    **label_font,
)

# Uniform axis limits
max_extent = max(length / 2, width / 2, height)
ax.set_xlim(-max_extent, max_extent)
ax.set_ylim(-max_extent, max_extent)
ax.set_zlim(0, 2 * max_extent)

# Remove axes, ticks, and grid
ax.set_xticks([])
ax.set_yticks([])
ax.set_zticks([])
ax.set_axis_off()

plt.show()
