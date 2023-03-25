#!/usr/bin/python3
"""
Module canUnlockAll
"""


def canUnlockAll(boxes):
    """
    Unlock the boxes
        Parameters: list
        Returns:Boolean
    """
    unlocked = [0]
    for box_id, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key < len(boxes) and key not in unlocked and key != box_id:
                unlocked.append(key)
    if len(unlocked) == len(boxes):
        return True
    return False
