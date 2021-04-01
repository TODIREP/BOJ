fun solution(n: Int, s: Int, a: Int, b: Int, fares: Array<IntArray>): Int {
    val limit = 30000000
    val taxi = Array(n) { IntArray(n) { limit } }
    
    repeat(n) {
        taxi[it][it] = 0
    }
    fares.forEach {
        val c = it[0] - 1
        val d = it[1] - 1
        taxi[c][d] = it[2]
        taxi[d][c] = it[2]
    }
    repeat(n) { check ->
        repeat(n) start@ { x ->
            if (x == check) return@start
            repeat(n) end@ { y ->
                if ((y == check) or (x == y)) return@end
                val distance = taxi[x][check] + taxi[check][y]
                taxi[x][y] = Math.min(taxi[x][y], distance)
            }
        }
    }
    var answer = taxi[s - 1][a - 1] + taxi[s - 1][b - 1]
    repeat(n) { check -> 
        answer = Math.min(answer, taxi[s - 1][check] + taxi[check][a - 1] + taxi[check][b - 1])
    }
    return answer
}