#!/usr/bin/python3
"""
Method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    num_boxes = len(boxes)
    unlocked_boxes = set([0])  # start with the first box unlocked
    new_keys = set(boxes[0])  # keys in the first box
    while new_keys:
        # Add any new unlocked boxes to the set
        unlocked_boxes |= new_keys
        # Find keys in newly unlocked boxes
        next_keys = set()
        for box in new_keys:
            if box < num_boxes:
                next_keys |= set(boxes[box])
        # Remove any keys for boxes that have already been unlocked
        next_keys -= unlocked_boxes
        # If all boxes are unlocked, return True
        if len(unlocked_boxes) == num_boxes:
            return True
        new_keys = next_keys
    # If not all boxes are unlocked, return False
    return False
