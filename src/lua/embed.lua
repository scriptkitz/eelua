--
-- Convert lua scripts to c array code
--

local function iif(expr, trueval, falseval)
  if (expr) then
    return trueval
  else
    return falseval
  end
end

local function stripfile(fname)
  local f = io.open(fname)
  local s = assert(f:read("*a"))
  f:close()

  -- strip tabs
  s = s:gsub("[\t]", "")

  -- strip any CRs
  s = s:gsub("[\r]", "")

  -- strip out comments
  s = s:gsub("\n%-%-[^\n]*", "")

  -- escape backslashes
  s = s:gsub("\\", "\\\\")

  -- strip duplicate line feeds
  s = s:gsub("\n+", "\n")

  -- strip out leading comments
  s = s:gsub("^%-%-\n", "")

  -- escape line feeds
  s = s:gsub("\n", "\\n")

  -- escape double quote marks
  s = s:gsub("\"", "\\\"")

  return s
end


local function writeline(out, s, continues)
  out:write("\t\"")
  out:write(s)
  out:write(iif(continues, "\"\n", "\",\n"))
end


local function writefile(out, fname, contents)
  local max = 1024

  out:write("\t/* " .. fname .. " */\n")

  -- break up large strings to fit in Visual Studio's string length limit
  local start = 1
  local len = contents:len()
  while start <= len do
    local n = len - start
    if n > max then n = max end
    local finish = start + n

    -- make sure I don't cut an escape sequence
    while contents:sub(finish, finish) == "\\" do
      finish = finish - 1
    end

    writeline(out, contents:sub(start, finish), finish < len)
    start = finish + 1
  end

  out:write("\n")
end

local basedir = path.getdirectory(os.getcwd())

function doembed()
  scripts = dofile(path.join(basedir, "lua/_manifest.lua"))
  script_cc = path.join(basedir, "scripts.cc")

  local out = io.open(script_cc, "w+b")
  out:write("/* eelua's internal lua scripts */\n")
  out:write("/* DO NOT EDIT - this file is autogenerated */\n\n")
  out:write("const char* builtin_scripts[] = {\n")

  for i, fn in ipairs(scripts) do
    fn = path.join(basedir, "lua/" .. fn)
    local s = stripfile(fn)
    writefile(out, fn, s)
  end

  out:write("\t0\n};\n\n");
  out:close()
end

