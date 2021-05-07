fun main() = with(System.`in`.bufferedReader()) {
    val bw = System.out.bufferedWriter()
    val a = readLine()
    val b = readLine()
    val aLen = a.length
    val bLen = b.length

    val lcs = Array(aLen) { IntArray(bLen) { 0 } }
    val word = Array(aLen) { MutableList(size = bLen, init = { Pair(-1, -1) }) }
    for (x in 0 until aLen) {
        for (y in 0 until bLen) {
            if (a[x] == b[y]) {
                word[x][y] = when (x == 0 || y == 0) {
                    true -> {
                        lcs[x][y] = 1
                        Pair(-1, -1)
                    }
                    false -> {
                        lcs[x][y] = lcs[x - 1][y - 1] + 1
                        Pair(x - 1, y - 1)
                    }
                }
            } else {
                if (x == 0 || y == 0) {
                    word[x][y] = when {
                        x == 0 && y == 0 -> Pair(0, 0)
                        x == 0 -> {
                            lcs[x][y] = lcs[x][y - 1]
                            Pair(x, y - 1)
                        }
                        else -> {
                            lcs[x][y] = lcs[x - 1][y]
                            Pair(x - 1, y)
                        }
                    }
                } else {
                    val max = lcs[x][y - 1].coerceAtLeast(lcs[x - 1][y].coerceAtLeast(lcs[x - 1][y - 1]))
                    word[x][y] = when (max) {
                        lcs[x][y - 1] -> {
                            lcs[x][y] = lcs[x][y - 1]
                            Pair(x, y - 1)
                        }
                        lcs[x - 1][y] -> {
                            lcs[x][y] = lcs[x - 1][y]
                            Pair(x - 1, y)
                        }
                        else -> {
                            lcs[x][y] = lcs[x - 1][y - 1]
                            Pair(x - 1, y - 1)
                        }
                    }
                }
            }
        }
    }
    bw.write("${lcs[aLen - 1][bLen - 1]}")
    if (lcs[aLen - 1][bLen - 1] > 0) {
        val result = StringBuilder()
        var wx = aLen - 1
        var wy = bLen - 1
        while (true) {
            val nx = word[wx][wy].first
            val ny = word[wx][wy].second
            if (nx == -1 || ny == -1) {
                result.append(a[wx])
                break
            }
            if (lcs[wx][wy] == 0) break
            if (lcs[wx][wy] != lcs[nx][ny]) result.append(a[wx])
            wx = nx
            wy = ny
        }
        result.reverse()
        bw.write("\n$result")
    }
    bw.close()
}