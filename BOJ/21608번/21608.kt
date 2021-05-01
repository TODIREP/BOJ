import java.util.*
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val arr = Array(n) { IntArray(n) { 0 } }
    val size = n * n
    val check: Array<Pair<Int, Int>?> = arrayOfNulls(size)
    val like = Array(size) { IntArray(4) }
    val dx = intArrayOf(1, 0, -1, 0)
    val dy = intArrayOf(0, 1, 0, -1)
    for (it in 0 until size) {
        val token = StringTokenizer(br.readLine())
        val student = token.nextToken().toInt()
        for (index in 0 until 4) { like[student - 1][index] = token.nextToken().toInt() }

        var favorite = -1
        var friend = 0
        for (x in 0 until n) {
            for (y in 0 until n) {
                if (arr[x][y] != 0) continue
                var count = 0
                for (dir in 0 until 4) {
                    val nx = x + dx[dir]
                    val ny = y + dy[dir]

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue
                    like[student - 1].forEach { value -> if (arr[nx][ny] == value) count++ }
                }
                if (count < favorite) continue
                if (count > favorite) {
                    favorite = count
                    friend = 0
                }
                check[friend++] = Pair(x, y)
            }
        }
        if (friend == 1) {
            val rx = check[0]!!.first
            val ry = check[0]!!.second
            arr[rx][ry] = student
            continue
        }

        var blank = -1
        var mx = 0
        var my = 0
        for (index in 0 until friend) {
            var count = 0
            val rx = check[index]!!.first
            val ry = check[index]!!.second

            for (dir in 0 until 4) {
                val nx = rx + dx[dir]
                val ny = ry + dy[dir]

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue
                if (arr[nx][ny] == 0) count++
            }

            if (count > blank) {
                blank = count
                mx = rx
                my = ry
            } else if (count == blank) {
                if (rx < mx) {
                    mx = rx
                    my = ry
                } else if (rx == mx) {
                    my = my.coerceAtMost(ry)
                }
            }
        }
        arr[mx][my] = student
    }

    var answer = 0
    for (x in 0 until n) {
        for (y in 0 until n) {
            var count = 0
            for (dir in 0 until 4) {
                val nx = x + dx[dir]
                val ny = y + dy[dir]

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue
                like[arr[x][y] - 1].forEach { value -> if (arr[nx][ny] == value) count++ }
            }
            if (count > 0) answer += (1 shl (count - 1)).toString(2).toInt()
        }
    }
    bw.write("$answer")
    bw.close()
}