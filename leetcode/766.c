bool isToeplitzMatrix(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int i;
    int current_check_row;
    int current_check_line;
    for(i = matrixRowSize - 1; i >= 0; i--)
    {
        current_check_row = i;
        current_check_line = 0;
        while((current_check_row + 1 < matrixRowSize) && (current_check_line + 1 < (*matrixColSizes)))
        {
            if(matrix[current_check_row][current_check_line] != matrix[current_check_row + 1][current_check_line + 1])
            {
                return false;
            }
            else
            {
                current_check_row++;
                current_check_line++;
            }
        }
    }
    for(i = 1; i < *matrixColSizes; i++)
    {
        current_check_line = i;
        current_check_row = 0;
        while((current_check_row + 1 < matrixRowSize) && (current_check_line + 1 < (*matrixColSizes)))
        {
            if(matrix[current_check_row][current_check_line] != matrix[current_check_row + 1][current_check_line + 1])
            {
                return false;
            }
            else
            {
                current_check_row++;
                current_check_line++;
            }
        }
    }
    return true;
}
