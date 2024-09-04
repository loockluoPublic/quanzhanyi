export const encode = (str: string) => {
  return btoa(btoa(str).slice(0, 7)).slice(0, 6);
};
