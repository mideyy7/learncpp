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

- **Key points** — the core concepts, condensed. Bullet points, not a paraphrase of the page's prose. Each bullet should say something the page's prose implies but doesn't state outright — a consequence, a rule derived from two facts combined, a "this is why X works" — not just a shorter rewording of a sentence that was already a bullet-length fact.
- **C++ internals** — how the compiler/runtime actually implements the behavior (memory layout, storage duration, calling convention, vtable mechanics, bit patterns, etc.) whenever the section touches on something with an underlying mechanism, even if learncpp.com itself doesn't go that deep. Trace the actual mechanism (e.g. show the modulo arithmetic or the bit pattern, don't just assert "it wraps around").
- **Performance implications** — anything relevant to cost: copies vs. moves, allocations, indirection, cache behavior.
- **Undefined behavior / gotchas** — explicitly flag UB, implementation-defined behavior, and common mistakes. This is the highest-value section for interview prep; don't bury it. **Every gotcha must be backed by a minimal, runnable code snippet that demonstrates it** (a few lines, with the surprising output as a comment) — a claim like "signed/unsigned comparison can silently invert" is not done until there's a snippet showing the exact comparison and its actual output.
- **Interview angle** — one or more concrete `Q:` / `A:` pairs, phrased the way an interviewer would actually ask it (not "know that X can happen"), followed by a model answer that reasons through the mechanism, not just a one-line "the answer is X." Prefer questions built around a code snippet the candidate has to trace through. Generic advice like "be ready to explain the rule" is not acceptable on its own — show the question and the reasoned answer.

Omit any of the above sections that genuinely don't apply to a given topic rather than padding them out. When in doubt about whether a section applies, err toward including it with a concrete example rather than a vague one-liner — a section with real depth is better than a section that's technically present but generic.

## Style

- Terse bullets, but terse means "no wasted words," not "shallow." A bullet can — and for gotchas/interview angle, should — be followed by a short code block; that's not padding.
- No restating the obvious ("a variable is a name for a value") — assume competence and focus on what's easy to get wrong.
- Every UB/gotcha claim and every interview-angle claim needs a concrete example (code snippet, or worked-through numbers) attached — asserting a fact without demonstrating it is treated as incomplete, not concise.
- Use `##`/`###` headers matching the section's own subheadings when the section is long enough to warrant it; otherwise keep it flat.
