fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val limit = 1e9.toInt()
    val (v, e) = br.readLine().split(" ").map(String::toInt)
    val link = Array(v) { IntArray(v) { limit } }
    for (it in 0 until e) {
        val (a, b, c) = br.readLine().split(" ").map(String::toInt)
        link[a - 1][b - 1] = c
    }

    for (visit in 0 until v) {
        for (start in 0 until v) {
            if (start == visit) continue
            for (end in 0 until v) {
                if (end == visit || end == start) continue
                link[start][end] = link[start][end].coerceAtMost(link[start][visit] + link[visit][end])
            }
        }
    }

    var answer = limit
    for (x in 0 until v) {
        for (y in 0 until v) answer = answer.coerceAtMost(link[x][y] + link[y][x])
    }
    bw.write("${if (answer == limit) -1 else answer}")
    bw.close()
}