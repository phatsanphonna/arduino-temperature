<script>
	import Navbar from '$lib/components/svelte/Navbar.svelte';
	import '../app.postcss';
</script>

<Navbar />

<main class="min-height container mx-auto flex flex-col gap-2 justify-center items-center">
	<slot />
</main>

<style>
	.min-height {
		min-height: calc(100vh - 4rem);
	}
</style>