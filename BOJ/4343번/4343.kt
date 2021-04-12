import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.pow
import kotlin.math.round
import kotlin.math.sqrt

data class Node(val a: Int, val b: Int, val dis: Double)

fun getDistance(a: Pair<Int, Int>, b: Pair<Int, Int>): Double {
    val xDis = (a.first - b.first).toDouble().pow(2)
    val yDis = (a.second - b.second).toDouble().pow(2)
    return round(sqrt(xDis + yDis) * 100) / 100
}

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()
    lateinit var root: IntArray
    fun findRoot(n: Int): Int {
        return when {
            root[n] < 0 -> n
            else -> {
                root[n] = findRoot(root[n])
                root[n]
            }
        }
    }

    fun unionRoot(a: Int, b: Int): Boolean {
        val aRoot = findRoot(a)
        val bRoot = findRoot(b)
        return when {
            (aRoot == bRoot) -> false
            else -> {
                root[bRoot] = aRoot
                true
            }
        }
    }

    repeat(t) {
        val (s, p) = readLine().split(" ").map(String::toInt)
        val network = mutableListOf<Pair<Int, Int>>()
        root = IntArray(p) { -1 }
        repeat(p) {
            val (x, y) = readLine().split(" ").map(String::toInt)
            network.add(Pair(x, y))
        }
        val link = mutableListOf<Node>()
        repeat(p) { start ->
            for (end in start + 1 until p) {
                link.add(Node(start, end, getDistance(network[start], network[end])))
            }
        }
        var res = 0.0
        run loop@{
            var cnt = p - s
            link.sortedBy { it.dis }.forEach { cur ->
                res = cur.dis
                if (unionRoot(cur.a, cur.b)) {
                    cnt--
                }
                if (cnt == 0) return@loop
            }
        }
        bw.write(String.format("%.2f\n", res))
    }
    bw.close()
}

fun main() {
    solution()
}