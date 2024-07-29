def rotate_submatrix(matrix, top_left, bottom_right):
    (r1, c1) = top_left
    (r2, c2) = bottom_right

    while r1 < r2 and c1 < c2:
        for i in range(c2 - c1):
            temp = matrix[r1][c1 + i]
            matrix[r1][c1 + i] = matrix[r2 - i][c1]
            matrix[r2 - i][c1] = matrix[r2][c2 - i]
            matrix[r2][c2 - i] = matrix[r1 + i][c2]
            matrix[r1 + i][c2] = temp
        
        r1 += 1
        c1 += 1
        r2 -= 1
        c2 -= 1

def process_matrix_operations(matrix, operations):
    for operation in operations:
        top_left = (operation[0], operation[1])
        bottom_right = (operation[2], operation[3])
        rotate_submatrix(matrix, top_left, bottom_right)
    
    return matrix

# Example usage:
matrix = [
    [10, 20, 30, 40], 
    [50, 60, 70, 80], 
    [90, 100, 110, 120], 
    [130, 140, 150, 160]
]
indices = [(0, 0, 3, 3), (1, 1, 2, 2)]
output = process_matrix_operations(matrix, indices)
print(output)
