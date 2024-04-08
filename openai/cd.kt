// Problem statement: Implement a "cd" command that behaves like the bash command and handles `.`, `..` and symlinks
fun cd(currentDir: String, newDir: String, symlinks: Map<String, String> = mapOf()): String {
  if (symlinks.contains(currentDir)) {
    return cd(symlinks[currentDir]!!, newDir, symlinks)
  }

  if (newDir.startsWith("/")) return newDir

  // current dir
  if (newDir.startsWith("./") && newDir.length > 1) {
    return cd(currentDir, newDir.drop(2), symlinks)
  }
  if (newDir == ".") return currentDir

  // parent
  if (newDir.startsWith("..")) {
    val currentDirParts = currentDir.split("/")
    return if (currentDirParts.size > 1 && currentDir.length > 1) {
      // we can go to the parent
      val parentDirParts = currentDirParts.dropLast(1)
      val newParentDir = if (parentDirParts.size == 1) "/" else parentDirParts.joinToString("/")
      cd(newParentDir, newDir.drop(3), symlinks)
    } else {
      // already at the root
      currentDir
    }
  }
  if (newDir.contains("/")) {
    val newDirParts = newDir.split("/")
    return cd("$currentDir/${newDirParts.first()}", newDirParts.drop(1).joinToString("/"), symlinks)
  }
  return if (newDir.isNotEmpty()) "$currentDir/$newDir" else currentDir
}

