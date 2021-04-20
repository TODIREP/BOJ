import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()

    repeat(t) {
        val coin = Array(3) { BooleanArray(3) { false } }
        repeat(3) { x ->
            readLine().split(" ").forEachIndexed { y, value ->
                coin[x][y] = (value == "T")
            }
        }
        fun valid(): Boolean {
            var cntH = 0
            var cntT = 0
            coin.forEach {
                it.forEach { value ->
                    when (value) {
                        true -> cntT++
                        false -> cntH++
                    }
                }
            }
            return when {
                cntH == 9 -> true
                cntT == 9 -> true
                else -> false
            }
        }
        var res = 100000
        val used = BooleanArray(8) { false }

        fun search(cnt: Int) {
            if (valid()) res = res.coerceAtMost(cnt)
            if (cnt == 8) return
            repeat(8) loop@ {
                if (used[it]) return@loop
                used[it] = true
                when (it) {
                    in 0..2 -> {
                        repeat(3) { x -> coin[x][it] = !coin[x][it] }
                        search(cnt + 1)
                        repeat(3) { x -> coin[x][it] = !coin[x][it] }
                    }
                    in 3..5 -> {
                        repeat(3) { y -> coin[it % 3][y] = !coin[it % 3][y] }
                        search(cnt + 1)
                        repeat(3) { y -> coin[it % 3][y] = !coin[it % 3][y] }
                    }
                    6 -> {
                        repeat(3) { index -> coin[index][index] = !coin[index][index] }
                        search(cnt + 1)
                        repeat(3) { index -> coin[index][index] = !coin[index][index] }
                    }
                    7 -> {
                        repeat(3) { index -> coin[index][2 - index] = !coin[index][2 - index] }
                        search(cnt + 1)
                        repeat(3) { index -> coin[index][2 - index] = !coin[index][2 - index] }
                    }
                }
                used[it] = false
            }
        }
        search(0)
        bw.write("${if (res == 100000) -1 else res}\n")
    }
    bw.close()
}