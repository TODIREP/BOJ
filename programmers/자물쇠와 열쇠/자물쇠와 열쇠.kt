class Solution {
    fun rotate(target: Array<IntArray>): Array<IntArray> {
        val size = target.size
        val res = Array(size) { IntArray(size) }
        repeat(size) { x -> 
            repeat(size) { y -> 
                res[x][y] = target[size - y - 1][x]
            }
        }
        return res
    }
    
    fun valid(key: Array<IntArray>, lock: Array<IntArray>, cx: Int, cy: Int, vx: Int, vy: Int): Boolean {
        val lockSize = lock.size
        val keySize = key.size
        
        val check = Array(lockSize) { IntArray(lockSize) }
        repeat(lockSize) { x -> 
            repeat(lockSize) { y -> 
                check[x][y] = lock[x][y]
            }
        }
        
        for (kx in vx until keySize) {
            for (ky in vy until keySize) {
                val rx = cx + kx - vx
                val ry = cy + ky - vy

                if ((rx >= lockSize) or (ry >= lockSize)) continue
                if (key[kx][ky] == 1) check[rx][ry] += 1
            }
        }
        
        repeat(lockSize) { x -> 
            repeat(lockSize) { y -> 
                if (check[x][y] != 1) return false
            }
        }
        
        return true
    }
    
    fun solution(key: Array<IntArray>, lock: Array<IntArray>): Boolean {
        var current = key
        val lockSize = lock.size
        val keySize = key.size
        
        repeat(lockSize) { x -> 
            repeat(lockSize) { y -> 
                repeat(4) {
                    current = rotate(current)
                    
                    repeat(keySize) { p -> 
                        repeat(keySize) { q -> 
                            if (valid(current, lock, x, y, p, q)) {
                                return true
                            }
                        }
                    }
                }
            }
        }
        
        return false
    }
}