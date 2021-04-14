import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.pow
import kotlin.math.sqrt

data class Camera(val x: Int, val y: Int, val r: Int)
data class Node(val a: Int, val b: Int, val dis: Double)

fun getDistance(a: Pair<Int, Int>, b: Pair<Int, Int>): Double {
    val xDis = (a.first - b.first).toDouble().pow(2)
    val yDis = (a.second - b.second).toDouble().pow(2)
    return sqrt(xDis + yDis)
}

lateinit var root: IntArray
fun findRoot(r: Int): Int {
    return when {
        (root[r] < 0) -> r
        else -> {
            root[r] = findRoot(root[r])
            root[r]
        }
    }
}

fun unionRoot(a: Int, b: Int): Boolean {
    val aRoot = findRoot(a)
    val bRoot = findRoot(b)
    if (aRoot == bRoot) return false
    root[bRoot] = aRoot
    return true
}

fun solution() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val t = readLine().toInt()
    repeat(t) {
        val w = readLine().toInt()
        val n = readLine().toInt()
        val cam = mutableListOf<Camera>()
        repeat(n) {
            val (x, y, r) = readLine().split(" ").map(String::toInt)
            cam.add(Camera(x, y, r))
        }
        val link = mutableListOf<Node>()
        link.add(Node(0, n + 1, w.toDouble()))
        root = IntArray(n + 2) { -1 }

        repeat(n) { index ->
            if (cam[index].x - cam[index].r <= 0) unionRoot(0, index + 1)
            else link.add(Node(0, index + 1, (cam[index].x - cam[index].r).toDouble()))
            if (cam[index].x + cam[index].r >= w) unionRoot(index + 1, n + 1)
            else link.add(Node(index + 1, n + 1, (w - cam[index].x - cam[index].r).toDouble()))

            for (next in index + 1 until n) {
                var distance = getDistance(Pair(cam[index].x, cam[index].y), Pair(cam[next].x, cam[next].y))
                if (distance <= (cam[index].r + cam[next].r)) {
                    link.add(Node(index + 1, next + 1, 0.0))
                } else {
                    distance -= (cam[index].r + cam[next].r).toDouble()
                    if (distance <= w) link.add(Node(index + 1, next + 1, distance))
                }
            }
        }
        var result = 0.0
        link.sortBy { it.dis }
        val size = link.size
        run loop@{
            repeat(size) {
                if (unionRoot(link[it].a, link[it].b)) {
                    if (findRoot(0) == findRoot(n + 1)) {
                        result = link[it].dis
                        return@loop
                    }
                }
            }
        }
        bw.write("${if (result == 0.0) 0 else String.format("%.10f", result / 2.0)}\n")
    }
    bw.close()
}

fun main() {
    solution()
}