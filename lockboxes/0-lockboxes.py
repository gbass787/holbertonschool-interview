#!/usr/bin/python3
"""
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Determine whether all boxes can be unlocked or not.

    Parameters:
    boxes (list): A list of lists, where each list represents a box,
    and contains integers representing the indices of the boxes that
    can be unlocked.

    Returns:
    bool: True if all boxes can be unlocked, False otherwise.
    """

    # Start with the first box unlocked
    unlocked_boxes = [0]

    # Iterate over each box
    for i in range(len(boxes)):

        # Check if the current box is empty
        if not boxes[i]:
            continue

        # Check each key in the current box
        for key in boxes[i]:

            # Check if the key unlocks a new box
            if key < len(boxes) and key not in unlocked_boxes and key != i:
                unlocked_boxes.append(key)

    # Check if all boxes are unlocked
    if len(unlocked_boxes) == len(boxes):
        return True

    return False
