fun lowerBound(target: LongArray, number: Long): Int {
    var left = 0
    var right = target.size
    while (left < right) {
        val mid = (left + right) / 2
        if (target[mid] >= number) right = mid
        else left = mid + 1
    }
    return left
}
fun upperBound(target: LongArray, number: Long): Int {
    var left = 0
    var right = target.size
    while (left < right) {
        val mid = (left + right) / 2
        if (target[mid] > number) right = mid
        else left = mid + 1
    }
    return left
}
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    val arr = Array(n) { LongArray(4) }
    for (it in 0 until n) { arr[it] = br.readLine().split(" ").map(String::toLong).toLongArray() }
    val prefixLeft = LongArray(n * n)
    val prefixRight = LongArray(n * n)
    for (a in 0 until n) {
        for (b in 0 until n) {
            prefixLeft[a * n + b] = arr[a][0] + arr[b][1]
            prefixRight[a * n + b] = arr[a][2] + arr[b][3]
        }
    }
    prefixLeft.sort()
    prefixRight.sort()
    var index = 0
    var answer: Long = 0
    val size = prefixLeft.size
    while (index < size) {
        val target = prefixLeft[index]
        val left = lowerBound(prefixRight, -target)
        val right = upperBound(prefixRight, -target)
        when {
            left >= size -> index++
            prefixRight[left] != -target -> index++
            else -> {
                val curLeft = lowerBound(prefixLeft, target)
                val curRight = upperBound(prefixLeft, target)
                answer += (right - left).toLong() * (curRight - curLeft).toLong()
                index = curRight
            }
        }
    }
    bw.write("$answer")
    bw.close()
}