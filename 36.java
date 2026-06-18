class Solution {
    public boolean isValidSudoku(char[][] board) {
        final int N = 9;

        HashSet<Character>[] rows = new HashSet[N];
        HashSet<Character>[] columns = new HashSet[N];
        HashSet<Character>[] boxes = new HashSet[N];

        for(int i=0;i<N;i++){
            rows[i] = new HashSet<Character>();
            columns[i] = new HashSet<Character>();
            boxes[i] = new HashSet<Character>();
        }

        for(int r = 0;r<N;r++){
            for(int c=0;c<N;c++){
                char value = board[r][c];
            // check if value is filled 
                if (value == '.' )continue;
                // check for rows 
                if(rows[r].contains(value)) return false;
                rows[r].add(value);

                // check for column 
                if(columns[c].contains(value)) return false;
                columns[c].add(value);

                // check for box 
                int idx = r/3*3 + c/3;

                if(boxes[idx].contains(value)) return false;
                boxes[idx].add(value);
            }
        }
        return true;
    }
}
