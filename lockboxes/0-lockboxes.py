#!/usr/bin/python3


def can_unlock_all(boxes):
    """
    Détermine si toutes les boîtes peuvent être ouvertes en utilisant les clés présentes dans les boîtes.

    :param boxes: Une liste de listes représentant les boîtes et les clés.
    :return: True si toutes les boîtes peuvent être ouvertes, False sinon.
    """

    opened_boxes = [False] * len(boxes)
    
    opened_boxes[0] = True
    
    stack = [0]
    
    while stack:
        current_box = stack.pop()
        
        for key in boxes[current_box]:
            if not opened_boxes[key]:
                opened_boxes[key] = True
                stack.append(key)

    return all(opened_boxes)
