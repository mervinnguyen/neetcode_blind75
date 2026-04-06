"""Sudoku validator that checks if a 9x9 board follows valid sudoku rules.

This module contains a solution to validate a partially filled 9x9 sudoku board
according to standard sudoku rules: each row, column, and 3x3 sub-box must
contain unique digits 1-9 (empty cells represented by '.').
"""


class Solution:
    """Solution class for validating sudoku boards."""
    
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        """Check if a sudoku board is valid according to sudoku rules.

        Args:
            board: A 9x9 grid represented as a list of lists, where each cell
                  contains either a digit '1'-'9' or '.' for empty cells.

        Returns:
            True if the board is valid, False otherwise.

        Example:
            >>> solution = Solution()
            >>> board = [["5","3",".",".","7",".",".",".","."],
            ...          ["6",".",".","1","9","5",".",".","."],
            ...          # ... rest of valid board
            ...         ]
            >>> solution.isValidSudoku(board)
            True
        """
        # Check each row for duplicates
        for row in range(9):
            seen = set()
            for i in range(9):
                if board[row][i] == ".":
                    continue
                if board[row][i] in seen:
                    return False
                seen.add(board[row][i])
        
        # Check each column for duplicates
        for column in range(9):
            seen = set()
            for i in range(9):
                if board[i][column] == ".":
                    continue
                if board[i][column] in seen:
                    return False
                seen.add(board[i][column])
        
        # Check each 3x3 sub-box for duplicates
        for square in range(9):
            seen = set()
            for i in range(3):
                for j in range(3):
                    # Map square index to row/col coordinates
                    row = (square // 3) * 3 + i
                    col = (square % 3) * 3 + j
                    if board[row][col] == ".":
                        continue
                    if board[row][col] in seen:
                        return False
                    seen.add(board[row][col])
        return True


# Test cases
board1 = [["5","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
          [".","9","8",".",".",".",".","6","."],    
            ["8",".",".",".","6",".",".",".","3"],
            ["4",".",".","8",".","3",".",".","1"],
            ["7",".",".",".","2",".",".",".","6"],
            [".","6",".",".",".",".","2","8","."],
            [".",".",".","4","1","9",".",".","5"],
            [".",".",".",".","8",".",".","7","9"]]

board2 = [["8","3",".",".","7",".",".",".","."],
          ["6",".",".","1","9","5",".",".","."],
            [".","9","8",".",".",".",".","6","."],    
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

solution = Solution()
print(solution.isValidSudoku(board1))
print(solution.isValidSudoku(board2))