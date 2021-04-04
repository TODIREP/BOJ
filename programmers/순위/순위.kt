class Solution {
    fun solution(n: Int, results: Array<IntArray>): Int {
        var answer = 0
        val reach = Array(n) { BooleanArray(n) { false } }
        
        results.forEach { result ->
            reach[result[0] - 1][result[1] - 1] = true
        }
        
        repeat(n) { check ->
            repeat(n) start@ { x -> 
                if (x == check) return@start
                repeat(n) target@ { y ->
                    if ((y == check) or (x == y)) return@target
                    
                    if ((reach[x][check]) and (reach[check][y])) {
                        reach[x][y] = true
                    }
                }
            }
        }
        
        repeat(n) { index -> 
            var res = 0
            repeat(n) { x -> 
                if ((reach[x][index]) or (reach[index][x])) res++
            }
            if (res == (n - 1)) answer++
        }
        return answer
    }
}