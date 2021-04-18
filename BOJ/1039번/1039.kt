import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun swapString(target: String, a: Int, b: Int): String {
    val res = StringBuilder()
    val size = target.length
    repeat(size) {
        when (it) {
            a -> res.append(target[b])
            b -> res.append(target[a])
            else -> res.append(target[it])
        }
    }
    return res.toString()
}
fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (n, k) = readLine().split(" ")
    val check = TreeMap<Int, TreeSet<String>>()
    val count = k.toInt()
    repeat(count) {
        val tree = TreeSet<String>()
        check[it + 1] = tree
    }
    val size = n.length
    var result = -1
    fun search(cur: String, cnt: Int) {
        if (cnt == count) {
            result = result.coerceAtLeast(cur.toInt())
            return
        }
        repeat(size) { i ->
            for (j in i + 1 until size) {
                if ((i == 0) and (cur[j] == '0')) continue
                val next = swapString(cur, i, j)
                if (!check[cnt + 1]!!.contains(next)) {
                    check[cnt + 1]!!.add(next)
                    search(next, cnt + 1)
                }
            }
        }
        return
    }
    search(n, 0)
    bw.write("$result")
    bw.close()
}