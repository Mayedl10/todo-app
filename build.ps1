Set-Location -Path $PSScriptRoot

$compiler = "g++"
$output = "main.exe"

$includeDirs = @(
    "include"
)

$srcFiles = @(
    "src/*.cpp"
)

$flags = @(
    "-Wall",
    "-std=c++20"
    # -O3
)

if (Test-Path $output) {
    Remove-Item $output
}

Invoke-Expression "$compiler $srcFiles -I $includeDirs $flags -o $output"

if (Test-Path $output) {
    Write-Output "Compilation Successful"
    Start-Process $output
} else {
    Write-Output "Compilation Failed"
}