import java.util.*

class Solution {
    fun solution(board: Array<IntArray>, moves: IntArray): Int {
        var answer = 0
        val stack = Stack<Int>()
        val size = board.size
        
        fun getTop(pos: Int): Int {
            repeat(size) { x ->
                if (board[x][pos - 1] != 0) {
                    val res = board[x][pos - 1]
                    board[x][pos - 1] = 0
                    return res
                }
            }
            return -1
        }
        
        for (move in moves) {
            val pick = getTop(move)
            if (pick == -1) continue
            
            when {
                stack.isEmpty() -> stack.add(pick)
                else -> {
                    when {
                        stack.peek() == pick -> {
                            answer += 2
                            stack.pop()
                        }
                        else -> stack.add(pick)
                    }
                }
            }
        }
        
        return answer
    }
}