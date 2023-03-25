#!/usr/bin/python3
"""
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """
    Check if all boxes can be unlocked starting from the first box (index 0)
    and using the keys contained in the boxes.

    Args:
        boxes (list of lists): The list of boxes, where each box
        is a list of integers representing
        the keys it contains.

    Returns:
        bool: True if all boxes can be unlocked, False otherwise.
    """
    # Keep track of the unlocked boxes, starting with the first box (index 0)
    unlocked_boxes = [0]
    # Iterate over the boxes
    for i, box in enumerate(boxes):
        # If the current box is already unlocked or it doesn't contain
        # any key, continue to the next box
        if i in unlocked_boxes or not box:
            continue
        # Iterate over the keys in the current box
        for key in box:
            # If the key opens a valid box (i.e., its index is
            # within the range of boxes and it's not
            # the current box), and the box hasn't been unlocked yet,
            # add it to the unlocked boxes
            if key < len(boxes) and key != i and key not in unlocked_boxes:
                unlocked_boxes.append(key)
    # Check if all boxes have been unlocked
    return len(unlocked_boxes) == len(boxes)
