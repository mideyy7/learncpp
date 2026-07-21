# CLAUDE.md

Study notes from [learncpp.com](https://www.learncpp.com/), organized for quant/LLD interview prep. See README.md for the directory layout.

Each session starts with no memory of prior conversations. This file, README.md, and the existing chapter files under `chapter_N/` are the only context available — treat them as the full source of truth for how to do this task, not just a description of it.

## Workflow: generating/updating a summary file

The user pastes the content of one learncpp.com section into the chat.

1. Identify the chapter and section number and title from the pasted content (e.g., "1.4 — Variable assignment and initialization").
2. Target file: `chapter_<N>/<N>.<M> - <title>.md`, matching the site's own numbering and title. Create `chapter_<N>/` if it doesn't exist yet.
3. If the file already exists, update it in place — merge in new material, don't duplicate or just append below old content.
4. Check the neighboring `.md` files in the same chapter before writing, and keep terminology/notation consistent with them (e.g. don't call something "storage duration" in one file and "lifetime" for the same concept in another).

## What the summary must contain

- **Key points** — the core concepts, condensed. Bullet points, not a paraphrase of the page's prose.
- **C++ internals** — how the compiler/runtime actually implements the behavior (memory layout, storage duration, calling convention, vtable mechanics, etc.) whenever the section touches on something with an underlying mechanism, even if learncpp.com itself doesn't go that deep.
- **Performance implications** — anything relevant to cost: copies vs. moves, allocations, indirection, cache behavior.
- **Undefined behavior / gotchas** — explicitly flag UB, implementation-defined behavior, and common mistakes. This is the highest-value section for interview prep; don't bury it.
- **Interview angle** — when the topic plausibly comes up in a quant or LLD interview, note the likely framing of the question and what a sharp answer looks like.

Omit any of the above sections that genuinely don't apply to a given topic rather than padding them out.

## Style

- Terse, bulleted. No restating the obvious ("a variable is a name for a value") — assume competence and focus on what's easy to get wrong.
- Code snippets only when they clarify something prose can't.
- Use `##`/`###` headers matching the section's own subheadings when the section is long enough to warrant it; otherwise keep it flat.
