import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun solution() {
    val bufferedRead = BufferedReader(InputStreamReader(System.`in`))
    val stringBuilder: StringBuilder = StringBuilder()

    var token = StringTokenizer(bufferedRead.readLine())
    val n: Int = Integer.parseInt(token.nextToken())
    val a = IntArray(n)
    val b = IntArray(n)

    token = StringTokenizer(bufferedRead.readLine())
    for (i in 0 until n) {
        a[i] = token.nextToken().toInt()
    }
    a.sort()

    token = StringTokenizer(bufferedRead.readLine())
    for (i in 0 until n) {
        b[i] = token.nextToken().toInt()
    }
    b.sortDescending()

    var sum = 0
    for (i in 0 until n) {
        sum += (a[i] * b[i])
    }

    stringBuilder.append(sum)
    println(stringBuilder.toString())
    bufferedRead.close()
}

fun main(args: Array<String>) {
    solution()
}