
class Solution
{
    char[][] board;
    boolean[][] visited;
    String word;
public
    boolean exist(char[][] board, String word)
    {
        if (board == null || board.length == 0 || word == null || word.trim() == "")
            return false;
        this.board = board;
        this.word = word;
        visited = new boolean[board.length][];
        createBoardAndFill();
        for (int i = 0; i < board.length; i++)
        {
            for (int j = 0; j < board[i].length; j++)
            {
                if (DFS(i, j, 0))
                    return true;
            }
        }
        return false;
    }
private
    void createBoardAndFill()
    {
        for (int i = 0; i < board.length; i++)
        {
            visited[i] = new boolean[board[i].length];
            Arrays.fill(visited[i], false);
        }
    }
private
    boolean DFS(int row, int col, int index)
    {
        if (index >= word.length())
            return true;
        if (row >= visited.length || row < 0 || col >= visited[row].length || col < 0 || visited[row][col] == true)
            return false;
        if (board[row][col] == word.charAt(index))
        {
            visited[row][col] = true;
            boolean isFound = DFS(row - 1, col, index + 1) || DFS(row + 1, col, index + 1) || DFS(row, col + 1, index + 1) || DFS(row, col - 1, index + 1);
            visited[row][col] = false;
            return isFound;
        }
        return false;
    }
}